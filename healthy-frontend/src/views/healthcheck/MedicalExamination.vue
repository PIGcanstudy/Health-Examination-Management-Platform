<!-- eslint-disable prettier/prettier -->
<!-- 体检诊台 -->
<template>
  <el-container style="height: 100vh;">
    <!-- 侧边栏 -->
    <el-aside :style="{maxWidth: isCollapsed ? '64px' : '300px'}">
      <!-- 伸缩按钮 -->
      <img src="@/assets/img-rom/slider.svg" style="cursor: pointer; width: 20px;" @click="isCollapsed = !isCollapsed">
      <PeopleList
        :style="isCollapsed ? 'display: none;' : 'min-width: 300px;'"
        :title="title"
        :checkbox-item="checkboxItem"
        :is-date-visible="isDateVisible"
        :external-form-items="formConfig.formItems"
      />
    </el-aside>

    <!-- 主要内容 -->
    <el-main>
      <MedicalInfo
        :current-progress="currentProgress"
        :progress-steps="progressSteps"
        :person-info="personInfo"
      />
      <BaseDataList :use-form="useForm" :form-data="formData" :table-data="tableData" :table-column-attribute="tableColumnAttribute">
      <!-- form表单区域 -->
      <template #form>
        <el-form-item label="体检项目">
          <el-input v-model="formData.tjxm"></el-input>
        </el-form-item>
        <el-form-item label="明细结果">
          <el-input v-model="formData.mxjg"></el-input>
        </el-form-item>
        <el-form-item label="单位">
          <el-input v-model="formData.unitName"></el-input>
        </el-form-item>
        <el-form-item label="参考值">
          <el-input v-model="formData.ckValue"></el-input>
        </el-form-item>
        <el-form-item label="提示">
          <el-input v-model="formData.ts"></el-input>
        </el-form-item>
        <el-form-item label="异常">
          <el-input v-model="formData.yc"></el-input>
        </el-form-item>
        </template>
      </BaseDataList>
    </el-main>
  </el-container>
</template>

<script setup>
import { ref, reactive } from 'vue'
import PeopleList from '@/components/peoplelist/PeopleList-Rom.vue'
import MedicalInfo from '@/components/medicalinfo/MedicalInfo.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'

// PeopleList的变量
const title = ref('人员查询')
const checkboxItem = ref(['未检', '已检'])
const isDateVisible = ref(false)
const formConfig = ref({
  formItems: [
    {
      type: 'input',
      name: '',
      placeholder: '请输入身份证号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入体检编号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入单位名称'
    }
  ]
})
// MedicalInfo的变量
const currentProgress = ref(1)
const progressSteps = ref(['登记', '在检', '总检', '已完成'])
const personInfo = ref({
  physical_id: '2202401120016',
  id_card: '510521199304017011',
  person_name: 'test-rom',
  sex: '男',
  age: '30',
  physical_type: '健康体检',
  mobile: '18980504604',
  unit_name: 'test-rom',
  marry_type: '',
  type_name: ''
})

//BaseDataList
// table列
const tableColumnAttribute = ref([
  { prop: 'tjxm', label: '体检项目', width: '240', align: 'center' },
  { prop: 'mxjg', label: '明细结果', width: '120', align: 'center' },
  { prop: 'unitName', label: '单位', width: '120', align: 'center' },
  { prop: 'ckValue', label: '参考值', width: '120', align: 'center' },
  { prop: 'ts', label: '提示', width: '120', align: 'center' },
  { prop: 'yc', label: '异常', width: '120', align: 'center' }
])
// table数据
const tableData = ref([
  {
    tjxm: '乐山市峨边盛和矿业',
    mxjg: '--',
    unitName: '健康体检',
    ckValue: '--',
    ts: '铁矿采选*',
    yc: '国有企业'
  }
])
const formData = reactive({
  tjxm: '',
  mxjg: '',
  unitName: '',
  ckValue: '',
  ts: '',
  yc: ''
})

// 本界面变量及函数
const isCollapsed = ref(false)
</script>
