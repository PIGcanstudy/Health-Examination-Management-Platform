<!-- 医生总检 -->
<template>
  <el-container>
    <el-aside>
      <PeopleList :use-header="useHeader"></PeopleList>
    </el-aside>
    <el-main>
      <!-- 主要内容 -->
      <MedicalInfo></MedicalInfo>
      <div>
        <el-button-group>
          <el-button type="primary" @click="toggleDrawer('summary')"> <el-icon name="edit"></el-icon> 阳性结果汇总 </el-button>

          <el-button type="primary" @click="toggleDrawer('details')"> <el-icon name="edit"></el-icon> 明细结果查看 </el-button>
        </el-button-group>

        <el-drawer v-if="isDrawerVisible.summary" title="阳性结果汇总" @close="closeDrawer('summary')">
          <BaseDataList></BaseDataList>
          <template #footer>
            <el-button @click="closeDrawer('summary')">关闭</el-button>
          </template>
        </el-drawer>

        <el-drawer v-if="isDrawerVisible.details" title="明细结果查看" @close="closeDrawer('details')">
          <!-- Content for Details Drawer -->
          <!-- ... -->
          <template #footer>
            <el-button @click="closeDrawer('details')">关闭</el-button>
          </template>
        </el-drawer>
      </div>
    </el-main>
  </el-container>
</template>

<script setup>
import PeopleList from '@/components/peoplelist/PeopleList-Rom.vue'
import MedicalInfo from '@/components/medicalinfo/MedicalInfo.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import { Edit } from '@element-plus/icons-vue'
import { ref } from 'vue'
import { ElDrawer, ElButton, ElIcon } from 'element-plus'

const isDrawerVisible = {
  summary: ref(false),
  details: ref(false)
}

const toggleDrawer = (drawerType) => {
  Object.keys(isDrawerVisible).forEach((key) => {
    isDrawerVisible[key].value = key === drawerType ? !isDrawerVisible[key].value : false
  })
}

const closeDrawer = (drawerType) => {
  isDrawerVisible[drawerType].value = false
}

//不使用头部标题栏
const useHeader = false
</script>

<style lang="scss" scoped></style>
