<template>
  <el-container>
    <el-aside>
      <PeopleList :use-header="false"></PeopleList>
    </el-aside>
    <el-main>
      <MedicalInfo></MedicalInfo>
      <div>
        <el-button-group>
          <el-button type="primary" @click="toggleDrawer('summary')"> 阳性结果汇总 </el-button>
          <el-button type="primary" @click="toggleDrawer('details')"> 明细结果查看 </el-button>
        </el-button-group>

        <div class="drawer">
          <el-drawer v-if="isDrawerVisible.summary" title="阳性结果汇总" @close="closeDrawer('summary')">
            <!-- 插入基础表格信息 -->
            <BaseDataList></BaseDataList>
            <template #footer>
              <el-button @click="closeDrawer('summary')">关闭</el-button>
            </template>
          </el-drawer>
        </div>

        <div class="drawer">
          <el-drawer v-if="isDrawerVisible.details" title="明细结果查看" @close="closeDrawer('details')">
            <template #footer>
              <el-button @click="closeDrawer('details')">关闭</el-button>
            </template>
          </el-drawer>
        </div>
        <!-- 体检详情组件 -->
        <Details></Details>
      </div>
    </el-main>
  </el-container>
</template>

<script setup>
import { ref } from 'vue'
import { ElDrawer, ElButton, ElButtonGroup } from 'element-plus'
import PeopleList from '@/components/peoplelist/PeopleList-Rom.vue'
import MedicalInfo from '@/components/medicalinfo/MedicalInfo.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import Details from '@/components/details/Details.vue'

// 抽屉组件显示
const isDrawerVisible = {
  summary: ref(false),
  details: ref(false)
}

const toggleDrawer = (drawerType) => {
  for (const key in isDrawerVisible) {
    isDrawerVisible[key].value = key === drawerType ? !isDrawerVisible[key].value : false
  }
}

// 关闭抽屉
const closeDrawer = (drawerType) => {
  isDrawerVisible[drawerType].value = false
}
</script>

<style lang="scss" scoped>
.drawer {
  height: 100%;
  width: 500px;
  margin: 20%;
}
</style>
