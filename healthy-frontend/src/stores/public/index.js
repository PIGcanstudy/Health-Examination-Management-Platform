import { defineStore } from 'pinia'
import { ref } from 'vue'
import {
  queryDictnameListApi,
  queryJobnameListApi,
  queryPackageProlistApi,
  queryPackagePronamelistApi,
  queryPlannameListApi,
  queryPlanProlistApi,
  querySelectionnameListApi,
  queryTermnameListApi,
  queryTypeTreeApi,
  queryUesrnameListApi
} from '@/apis/public/index.js'

export const usePublicStore = defineStore('public', () => {
  // 重写方法
  //获取字典数据名称列表（用于输入表单下拉列表）
  const getDictnameList = async (params) => {
    return await queryDictnameListApi(params)
  }
  //获取工种名称列表（分页＋条件）
  const getJobnameList = async (params) => {
    return await queryJobnameListApi(params)
  }
  //获取组合项目列表（条件＋分页）
  const getPackageProlist = async (params) => {
    return await queryPackageProlistApi(params)
  }
  //获取组合项目名称列表（用于输入表单下拉列表）
  const getPackagePronamelist = async (params) => {
    return await queryPackagePronamelistApi(params)
  }
  //获取套餐名称列表（条件+分页）
  const getPlannameList = async (params) => {
    return await queryPlannameListApi(params)
  }
  //获取套餐组合项目列表
  const getPlanProlist = async (params) => {
    return await queryPlanProlistApi(params)
  }
  //科室名称列表
  const getSelectionnameList = async (params) => {
    return await querySelectionnameListApi(params)
  }
  const getTermnameList = async (params) => {
    return await queryTermnameListApi(params)
  }
  const getTypeTree = async (params) => {
    return await queryTypeTreeApi(params)
  }
  const getUesrnameList = async (params) => {
    return await queryUesrnameListApi(params)
  }

  // 暴露出的数据
  return {
    getDictnameList,
    getJobnameList,
    getPackageProlist,
    getPackagePronamelist,
    getPlannameList,
    getPlanProlist,
    getSelectionnameList,
    getTermnameList,
    getTypeTree,
    getUesrnameList
  }
})
